
// PizzeriaDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "Pizzeria.h"
#include "PizzeriaDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de diálogo de CPizzeriaDlg



CPizzeriaDlg::CPizzeriaDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_PIZZERIA_DIALOG, pParent)
	, Cantidad(0)
	, total(0)
	, tamano(250)
	, peperoni(FALSE)
	, jamon(FALSE)
	, carne(FALSE)
	, pimiento(FALSE)
	, cebolla(FALSE)
	, jalape(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPizzeriaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, Cantidad);
	DDX_Text(pDX, IDC_EDIT3, total);
	DDX_Check(pDX, IDC_CHECK1, peperoni);
	DDX_Check(pDX, IDC_CHECK2, jamon);
	DDX_Check(pDX, IDC_CHECK3, carne);
	DDX_Check(pDX, IDC_CHECK4, pimiento);
	DDX_Check(pDX, IDC_CHECK5, cebolla);
	DDX_Check(pDX, IDC_CHECK6, jalape);
}

BEGIN_MESSAGE_MAP(CPizzeriaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CPizzeriaDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CPizzeriaDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CPizzeriaDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CPizzeriaDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_BUTTON1, &CPizzeriaDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPizzeriaDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Controladores de mensajes de CPizzeriaDlg

BOOL CPizzeriaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(true);
	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CPizzeriaDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CPizzeriaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CPizzeriaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPizzeriaDlg::OnBnClickedRadio1(){
	UpdateData();
	tamano = 250;
	UpdateData(false);
}


void CPizzeriaDlg::OnBnClickedRadio2(){
	UpdateData();
	tamano = 200;
	UpdateData(false);
}


void CPizzeriaDlg::OnBnClickedRadio3(){
	UpdateData();
	tamano = 150;
	UpdateData(false);
}


void CPizzeriaDlg::OnBnClickedRadio4(){
	UpdateData();
	tamano = 100;
	UpdateData(false);
}


void CPizzeriaDlg::OnBnClickedButton1(){
	UpdateData(true);
	int temptam = tamano;
	temptam = (peperoni) ? temptam += 15 : temptam;
	temptam = (jamon) ? temptam += 15 : temptam;
	temptam = (carne) ? temptam += 15 : temptam;
	temptam = (pimiento) ? temptam += 10 : temptam;
	temptam = (cebolla) ? temptam += 10 : temptam;
	temptam = (jalape) ? temptam += 10 : temptam;
	total = temptam*Cantidad;
	UpdateData(false);
}


void CPizzeriaDlg::OnBnClickedButton2(){
	UpdateData();
	total = 0;
	Cantidad = 0;
	UpdateData(false);
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(true);
	((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(false);
	((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(false);
	((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(false);
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(false);
	((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(false);
	((CButton*)GetDlgItem(IDC_CHECK3))->SetCheck(false);
	((CButton*)GetDlgItem(IDC_CHECK4))->SetCheck(false);
	((CButton*)GetDlgItem(IDC_CHECK5))->SetCheck(false);
	((CButton*)GetDlgItem(IDC_CHECK6))->SetCheck(false);
}
