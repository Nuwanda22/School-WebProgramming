
// My First MFC ProjectView.cpp : CMyFirstMFCProjectView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "My First MFC Project.h"
#endif

#include "My First MFC ProjectDoc.h"
#include "My First MFC ProjectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyFirstMFCProjectView

IMPLEMENT_DYNCREATE(CMyFirstMFCProjectView, CView)

BEGIN_MESSAGE_MAP(CMyFirstMFCProjectView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMyFirstMFCProjectView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMyFirstMFCProjectView ����/�Ҹ�

CMyFirstMFCProjectView::CMyFirstMFCProjectView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMyFirstMFCProjectView::~CMyFirstMFCProjectView()
{
}

BOOL CMyFirstMFCProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMyFirstMFCProjectView �׸���

void CMyFirstMFCProjectView::OnDraw(CDC* /*pDC*/)
{
	CMyFirstMFCProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMyFirstMFCProjectView �μ�


void CMyFirstMFCProjectView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMyFirstMFCProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMyFirstMFCProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMyFirstMFCProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMyFirstMFCProjectView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMyFirstMFCProjectView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMyFirstMFCProjectView ����

#ifdef _DEBUG
void CMyFirstMFCProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CMyFirstMFCProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyFirstMFCProjectDoc* CMyFirstMFCProjectView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyFirstMFCProjectDoc)));
	return (CMyFirstMFCProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyFirstMFCProjectView �޽��� ó����
