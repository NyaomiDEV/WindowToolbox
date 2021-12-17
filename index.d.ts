export function SetWindowPosition(hWnd: Buffer, hWndInsertAfter: Buffer, x: number, y: number, cx: number, cy: number, uFlags: number): boolean | undefined;
export function ParentToDesktop(hWnd: Buffer): boolean | undefined;

export const HWND_BOTTOM = 1;
export const HWND_NOTOPMOST = -2;
export const HWND_TOP = 0;
export const HWND_TOPMOST = -1;

/*
 * SetWindowPos Flags
 */
export const SWP_NOSIZE = 0x0001;
export const SWP_NOMOVE = 0x0002;
export const SWP_NOZORDER = 0x0004;
export const SWP_NOREDRAW = 0x0008;
export const SWP_NOACTIVATE = 0x0010;
export const SWP_FRAMECHANGED = 0x0020; /* The frame changed: send WM_NCCALCSIZE */
export const SWP_SHOWWINDOW = 0x0040;
export const SWP_HIDEWINDOW = 0x0080;
export const SWP_NOCOPYBITS = 0x0100;
export const SWP_NOOWNERZORDER = 0x0200; /* Don't do owner Z ordering */
export const SWP_NOSENDCHANGING = 0x0400; /* Don't send WM_WINDOWPOSCHANGING */

export const SWP_DRAWFRAME = 0x0020; // SWP_FRAMECHANGED
export const SWP_NOREPOSITION = 0x0200; // SWP_NOOWNERZORDER

/* WINVER >= 0x0400 */
export const SWP_DEFERERASE = 0x2000; // same as SWP_DEFERDRAWING
export const SWP_ASYNCWINDOWPOS = 0x4000; // same as SWP_CREATESPB
