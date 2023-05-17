
// PizzeriaDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CPizzeriaDlg
class CPizzeriaDlg : public CDialogEx
{
// Construcción
public:
	CPizzeriaDlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PIZZERIA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int Cantidad;
	int total;
	int tamano;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedButton1();
	BOOL peperoni;
	BOOL jamon;
	BOOL carne;
	BOOL pimiento;
	BOOL cebolla;
	BOOL jalape;
	afx_msg void OnBnClickedButton2();
};
