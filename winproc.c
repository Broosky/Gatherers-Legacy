/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Program Name: Gatherers (C)                                                                                            //
//  Author: Jeffrey Bednar                                                                                                 //
//  Copyright: Illusion Interactive, 2011                                                                                  //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _WINPROC_C_
#define _WINPROC_C_
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "main.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Future:
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - Put the menu handle into a stack variable because we use it many times.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void __cdecl PROC_BuildHelper(int iType, GLOBALS* p_Globals) {
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Uncheck all of the menu items
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CheckMenuItem((*p_Globals).hMenu, MENU_BUILD_NONE, MF_UNCHECKED);
    CheckMenuItem((*p_Globals).hMenu, MENU_BUILD_WORKER, MF_UNCHECKED);
    CheckMenuItem((*p_Globals).hMenu, MENU_BUILD_COMMAND, MF_UNCHECKED);
    CheckMenuItem((*p_Globals).hMenu, MENU_BUILD_MINERAL, MF_UNCHECKED);
    CheckMenuItem((*p_Globals).hMenu, MENU_BUILD_SUPPLY, MF_UNCHECKED);
    CheckMenuItem((*p_Globals).hMenu, MENU_BUILD_REFINERY, MF_UNCHECKED);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Check the one we want.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    switch(iType) {
        case ENTITY_WORKER: {
            CheckMenuItem((*p_Globals).hMenu, MENU_BUILD_WORKER, MF_CHECKED);
            break;
        }
        case ENTITY_COMMAND: {
            CheckMenuItem((*p_Globals).hMenu, MENU_BUILD_COMMAND, MF_CHECKED);
            break;
        }
        case ENTITY_MINERAL: {
            CheckMenuItem((*p_Globals).hMenu, MENU_BUILD_MINERAL, MF_CHECKED);
            break;
        }
        case ENTITY_SUPPLY: {
            CheckMenuItem((*p_Globals).hMenu, MENU_BUILD_SUPPLY, MF_CHECKED);
            break;
        }
        case ENTITY_REFINERY: {
            CheckMenuItem((*p_Globals).hMenu, MENU_BUILD_REFINERY, MF_CHECKED);
            break;
        }
        default: {
            CheckMenuItem((*p_Globals).hMenu, MENU_BUILD_NONE, MF_CHECKED);
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK PROC_WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_COMMAND: {
            switch(LOWORD(wParam)) {
                case MENU_FILE_FREE: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    (*p_Globals).iMineralCount += 2000;
                    (*p_Globals).iGasCount += 2000;
                    break;
                }
                case MENU_FILE_EXIT: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    PostMessage(hWnd, WM_CLOSE, 0, 0);
                    break;
                }
                case MENU_FILE_PRINT: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY_PrintList(p_Globals);
                    break;
                }
                case MENU_DELETE_SELECTED: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY_DeleteSelected(p_Globals);
                    break;
                }
                case MENU_DELETE_ALL: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY_DeleteAll(p_Globals);
                    break;
                }
                case MENU_DELETE_WORKER: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY_DeleteEntityType(ENTITY_WORKER, p_Globals);
                    break;
                }
                case MENU_DELETE_COMMAND: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY_DeleteEntityType(ENTITY_COMMAND, p_Globals);
                    break;
                }
                case MENU_DELETE_MINERAL: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY_DeleteEntityType(ENTITY_MINERAL, p_Globals);
                    break;
                }
                case MENU_DELETE_SUPPLY: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY_DeleteEntityType(ENTITY_SUPPLY, p_Globals);
                    break;
                }
                case MENU_DELETE_REFINERY: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY_DeleteEntityType(ENTITY_REFINERY, p_Globals);
                    break;
                }
                case MENU_BUILD_NONE: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    PROC_BuildHelper(ENTITY_NONE, p_Globals);
                    (*p_Globals).iBuildType = ENTITY_WORKER;
                    (*p_Globals).bCreate = 0;
                    break;
                }
                case MENU_BUILD_WORKER: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    PROC_BuildHelper(ENTITY_WORKER, p_Globals);
                    (*p_Globals).iBuildType = ENTITY_WORKER;
                    (*p_Globals).bCreate = 1;
                    break;
                }
                case MENU_BUILD_COMMAND: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    PROC_BuildHelper(ENTITY_COMMAND, p_Globals);
                    (*p_Globals).iBuildType = ENTITY_COMMAND;
                    (*p_Globals).bCreate = 1;
                    break;
                }
                case MENU_BUILD_MINERAL: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    PROC_BuildHelper(ENTITY_MINERAL, p_Globals);
                    (*p_Globals).iBuildType = ENTITY_MINERAL;
                    (*p_Globals).bCreate = 1;
                    break;
                }
                case MENU_BUILD_SUPPLY: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    PROC_BuildHelper(ENTITY_SUPPLY, p_Globals);
                    (*p_Globals).iBuildType = ENTITY_SUPPLY;
                    (*p_Globals).bCreate = 1;
                    break;
                }
                case MENU_BUILD_REFINERY: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    PROC_BuildHelper(ENTITY_REFINERY, p_Globals);
                    (*p_Globals).iBuildType = ENTITY_REFINERY;
                    (*p_Globals).bCreate = 1;
                    break;
                }
                case MENU_OPTIONS_BEGIN: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    if((*p_Globals).bBegin) {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_BEGIN, MF_UNCHECKED);
                        (*p_Globals).bBegin = !(*p_Globals).bBegin;
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        // Stop each entity that was moving.
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        ENTITY* p_Current = (*p_Globals).p_RootEntity;
                        while(p_Current) {
                            (*p_Current).bIsInMotion = 0;
                            p_Current = (ENTITY*)(*p_Current).p_Next;
                        }
                    }
                    else {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_BEGIN, MF_CHECKED);
                        (*p_Globals).bBegin = !(*p_Globals).bBegin;
                    }
                    break;
                }
                case MENU_OPTIONS_DIAGNOSTICS: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    if((*p_Globals).bDiagnostics) {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_DIAGNOSTICS, MF_UNCHECKED);
                        (*p_Globals).bDiagnostics = !(*p_Globals).bDiagnostics;
                    }
                    else {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_DIAGNOSTICS, MF_CHECKED);
                        (*p_Globals).bDiagnostics = !(*p_Globals).bDiagnostics;
                    }
                    break;
                }
                case MENU_OPTIONS_MASKING: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    if((*p_Globals).bEnableMasking) {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_MASKING, MF_UNCHECKED);
                        (*p_Globals).bEnableMasking = !(*p_Globals).bEnableMasking;
                    }
                    else {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_MASKING, MF_CHECKED);
                        (*p_Globals).bEnableMasking = !(*p_Globals).bEnableMasking;
                    }
                    break;
                }
                case MENU_OPTIONS_RESOURCES: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    if((*p_Globals).bDrawResources) {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_RESOURCES, MF_UNCHECKED);
                        (*p_Globals).bDrawResources = !(*p_Globals).bDrawResources;
                    }
                    else {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_RESOURCES, MF_CHECKED);
                        (*p_Globals).bDrawResources = !(*p_Globals).bDrawResources;
                    }
                    break;
                }
                case MENU_OPTIONS_FULLSCREEN: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    if((*p_Globals).bFullScreen) {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_FULLSCREEN, MF_UNCHECKED);
                        (*p_Globals).bFullScreen = !(*p_Globals).bFullScreen;
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        // Change double buffer settings.
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        SetWindowLongPtr(hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);
                        MISC_ResizeWindow(hWnd, CLIENT_WIDTH, CLIENT_HEIGHT);
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        DBLBUF_Resize(p_DblBuf, hWnd, RGB(0, 0, 0), p_Globals);
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        // Remember to reset the graphics mode to allow the rendering engine to work.
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        RENDER_Init(p_DblBuf);
                    }
                    else {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_FULLSCREEN, MF_CHECKED);
                        (*p_Globals).bFullScreen = !(*p_Globals).bFullScreen;
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        // Change double buffer settings.
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        // Last argument is 1 because the menu needs to be redrawn when the window area resizes.
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        SetWindowLongPtr(hWnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
                        MoveWindow(hWnd, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), 1);
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        DBLBUF_Resize(p_DblBuf, hWnd, RGB(0, 0, 0), p_Globals);
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        // Remember to reset the graphics mode to allow the rendering engine to work.
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        RENDER_Init(p_DblBuf);
                    }
                    break;
                }
                case MENU_OPTIONS_STATUSES: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    if((*p_Globals).bDrawStatuses) {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_STATUSES, MF_UNCHECKED);
                        (*p_Globals).bDrawStatuses = !(*p_Globals).bDrawStatuses;
                    }
                    else {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_STATUSES, MF_CHECKED);
                        (*p_Globals).bDrawStatuses = !(*p_Globals).bDrawStatuses;
                    }
                    break;
                }
                case MENU_OPTIONS_SHOW_MINOR: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    if((*p_Globals).bDrawMinor) {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_SHOW_MINOR, MF_UNCHECKED);
                        (*p_Globals).bDrawMinor = !(*p_Globals).bDrawMinor;
                    }
                    else {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_SHOW_MINOR, MF_CHECKED);
                        (*p_Globals).bDrawMinor = !(*p_Globals).bDrawMinor;
                    }
                    break;
                }
                case MENU_OPTIONS_SHOW_MAJOR: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    if((*p_Globals).bDrawMajor) {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_SHOW_MAJOR, MF_UNCHECKED);
                        (*p_Globals).bDrawMajor = !(*p_Globals).bDrawMajor;
                    }
                    else {
                        CheckMenuItem((*p_Globals).hMenu, MENU_OPTIONS_SHOW_MAJOR, MF_CHECKED);
                        (*p_Globals).bDrawMajor = !(*p_Globals).bDrawMajor;
                    }
                    break;
                }
                case MENU_CLEAR_SELECTED: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY* p_Current = (*p_Globals).p_RootEntity;
                    while(p_Current) {
                        (*p_Current).bIsSelected = 0;
                        p_Current = (ENTITY*)(*p_Current).p_Next;
                    }
                    break;
                }
                case MENU_CLEAR_MINERAL_COUNT: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    (*p_Globals).iMineralCount = 0;
                    break;
                }
                case MENU_CLEAR_GAS_COUNT: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    (*p_Globals).iGasCount = 0;
                    break;
                }
                case MENU_CLEAR_ALL_COUNT: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    (*p_Globals).iMineralCount = 0;
                    (*p_Globals).iGasCount = 0;
                    break;
                }
                case MENU_SORT_WORKERS: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY_SortToFront(WORKERS_TO_FRONT, p_Globals);
                    break;
                }
                case MENU_SORT_MINERALS: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY_SortToFront(MINERALS_TO_FRONT, p_Globals);
                    break;
                }
                case MENU_SORT_COMMANDS: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY_SortToFront(COMMANDS_TO_FRONT, p_Globals);
                    break;
                }
                case MENU_SORT_SUPPLY: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY_SortToFront(SUPPLIES_TO_FRONT, p_Globals);
                    break;
                }
                case MENU_SORT_REFINERIES: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY_SortToFront(REFINERIES_TO_FRONT, p_Globals);
                    break;
                }
                case MENU_SORT_OBSTACLES: {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ENTITY_SortToFront(OBSTACLES_TO_FRONT, p_Globals);
                }
            }
            break;
        }
        case WM_SIZE: {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(p_DblBuf != NULL) {
                DBLBUF_Resize(p_DblBuf, hWnd, RGB(0, 0, 0), p_Globals);
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // Remember to reset the graphics mode to allow the rendering engine to work.
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                RENDER_Init(p_DblBuf);
            }
            break;
        }
        case WM_LBUTTONUP: {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(!(*p_Globals).bCreate) {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // Allow the operation to work when the mouse is dragged from all directions.
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                int iSavedX = (*p_Globals).iMouseX;
                int iSavedY = (*p_Globals).iMouseY;
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if((*p_Globals).iMouseX < (*p_Globals).iOldMouseX) {
                    int iHolder = (*p_Globals).iMouseX;
                    (*p_Globals).iMouseX = (*p_Globals).iOldMouseX;
                    (*p_Globals).iOldMouseX = iHolder;
                }
                if((*p_Globals).iMouseY < (*p_Globals).iOldMouseY) {
                    int iHolder = (*p_Globals).iMouseY;
                    (*p_Globals).iMouseY = (*p_Globals).iOldMouseY;
                    (*p_Globals).iOldMouseY = iHolder;
                }
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                ENTITY* p_Current = (*p_Globals).p_RootEntity;
                while(p_Current) {
                    if(
                        (*p_Current).CenterPoint.fX >= (*p_Globals).iOldMouseX &&
                        (*p_Current).CenterPoint.fX <= (*p_Globals).iMouseX &&
                        (*p_Current).CenterPoint.fY >= (*p_Globals).iOldMouseY &&
                        (*p_Current).CenterPoint.fY <= (*p_Globals).iMouseY
                    ) {
                        (*p_Current).bIsSelected = !(*p_Current).bIsSelected;
                    }
                    p_Current = (ENTITY*)(*p_Current).p_Next;
                }
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // Incase the points were swapped, reset the original values.
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                (*p_Globals).iMouseX = iSavedX;
                (*p_Globals).iMouseY = iSavedY;
            }
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            (*p_Globals).bDrawSelectionRect = 0;
            break;
        }
        case WM_LBUTTONDOWN: {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // For mouse drag selection.
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            (*p_Globals).iOldMouseX = (*p_Globals).iMouseX;
            (*p_Globals).iOldMouseY = (*p_Globals).iMouseY;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // If build mode is selected, create an entity at the mouse position.
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if((*p_Globals).bCreate) {
                ENTITY_Create(
                    (FPOINT){(*p_Globals).iMouseX, (*p_Globals).iMouseY},
                    (*p_Globals).iBuildType,
                    p_Images,
                    p_Globals
                );
            }
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // Build mode is not selected, therefore allow the left mouse click to select entities.
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            else {
                int bIsSomethingThere = 0;
                ENTITY* p_Current = (*p_Globals).p_RootEntity;
                while(p_Current) {
                    if(ENTITY_WithinPoint(p_Current, (FPOINT){(*p_Globals).iMouseX, (*p_Globals).iMouseY})) {
                        (*p_Current).bIsSelected = !(*p_Current).bIsSelected;
                        bIsSomethingThere = 1;
                    }
                    p_Current = (ENTITY*)(*p_Current).p_Next;
                }
                if(!bIsSomethingThere) {
                    p_Current = (*p_Globals).p_RootEntity;
                    while(p_Current) {
                        (*p_Current).bIsSelected = 0;
                        p_Current = (ENTITY*)(*p_Current).p_Next;
                    }
                }
            }
            break;
        }
        case WM_RBUTTONDOWN: {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            int iMoveableCount = 0;
            ENTITY* p_Resource = NULL;
            ENTITY* p_Current = (*p_Globals).p_RootEntity;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // Loop through all of the entities and check to see if we right-clicked on a resource.
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            while(p_Current && !p_Resource) {
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // Hijack this loop to keep track of how many moveable entities are selected.
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if((*p_Current).bIsMovable) {
                    if((*p_Current).bIsSelected) {
                        iMoveableCount++;
                    }
                }
                switch((*p_Current).iType) {
                    case ENTITY_MINERAL: {
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        // True, if I right clicked on a mineral field.
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        if(ENTITY_WithinPoint(p_Current, (FPOINT){(*p_Globals).iMouseX, (*p_Globals).iMouseY})) {
                            /////////////////////////////////////////////////////////////////////////////////////////////////
                            // We want to make all the selected entities harvest THAT particular mineral field.
                            /////////////////////////////////////////////////////////////////////////////////////////////////
                            p_Resource = p_Current;
                        }
                        break;
                    }
                    case ENTITY_REFINERY: {
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        // True, if I right clicked on a refinery.
                        /////////////////////////////////////////////////////////////////////////////////////////////////////
                        if(ENTITY_WithinPoint(p_Current, (FPOINT){(*p_Globals).iMouseX, (*p_Globals).iMouseY})) {
                            /////////////////////////////////////////////////////////////////////////////////////////////////
                            // We want to make all the selected entities harvest THAT particular refinery.
                            /////////////////////////////////////////////////////////////////////////////////////////////////
                            p_Resource = p_Current;
                        }
                    }
                }
                p_Current = (ENTITY*)(*p_Current).p_Next;
            }
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            int iI;
            int iMemory;
            FPOINT* p_DestinationPoints = NULL;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // We did not click on a resource, therefore we have to move the selected entities.
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(!p_Resource) {
                iMemory = sizeof(FPOINT) * iMoveableCount;
                p_DestinationPoints = (FPOINT*)malloc(iMemory);
                (*p_Globals).iRunningHeap += iMemory;
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // Future:
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // - Figure out the average size of the entities to be moved.
                // - Do not create destination points if we are harvesting a resource. There is no need.
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                int iColumn = 1;
                int iColumnLimit = sqrt(iMoveableCount);
                FPOINT Placement = {(*p_Globals).iMouseX, (*p_Globals).iMouseY};
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                for(iI = 0; iI < iMoveableCount; iI++) {
                    p_DestinationPoints[iI] = Placement;
                    /////////////////////////////////////////////////////////////////////////////////////////////////////////
                    if(iColumn >= iColumnLimit) {
                        Placement.fY += (*p_Images).Worker[0].Bitmap.bmHeight;
                        Placement.fX = (*p_Globals).iMouseX;
                        iColumn = 1;
                    }
                    else {
                        Placement.fX += (*p_Images).Worker[0].Bitmap.bmWidth;
                        iColumn++;
                    }
                }
                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                iI = 0;
            }
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // Loop through all of the entities and move them if they are selected.
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            p_Current = (*p_Globals).p_RootEntity;
            while(p_Current) {
                if((*p_Current).bIsSelected) {
                    (*p_Current).bIsSelected = 0;
                    if((*p_Current).bIsMovable) {
                        if(p_Resource) {
                            (*p_Current).p_Operating = (struct ENTITY*)p_Resource;
                        }
                        else {
                            (*p_Current).p_Operating = NULL;
                            ENTITY_MoveToPoint(p_Current, p_DestinationPoints[iI++], p_Globals);
                        }
                    }
                }
                p_Current = (ENTITY*)(*p_Current).p_Next;
            }
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(p_DestinationPoints) {
                free(p_DestinationPoints);
                (*p_Globals).iRunningHeap -= iMemory;
            }
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            break;
        }
        case WM_MOUSEMOVE: {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            (*p_Globals).iMouseX = LOWORD(lParam);
            (*p_Globals).iMouseY = HIWORD(lParam);
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // For mouse drag selection.
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(wParam == MK_LBUTTON) {
                (*p_Globals).bDrawSelectionRect = 1;
            }
            break;
        }
        case WM_KEYDOWN: {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            switch(wParam) {
                case VK_ESCAPE: {
                    PostMessage(hWnd, WM_CLOSE, 0, 0);
                }
            }
            break;
        }
        case WM_CLOSE: {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            PostQuitMessage(0);
            break;
        }
        default: {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // I handled a message.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
