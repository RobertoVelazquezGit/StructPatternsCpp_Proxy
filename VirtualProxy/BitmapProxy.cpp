#include "BitmapProxy.h"
#include <iostream>

#include "Bitmap.h"

BitmapProxy::BitmapProxy() :BitmapProxy{ "" } {

}

BitmapProxy::~BitmapProxy() {
	delete m_pBitmap;
}

BitmapProxy::BitmapProxy(const std::string& fileName) {
	m_pBitmap = new Bitmap{ fileName };
}

void BitmapProxy::Display() {
	if (!m_Loaded) {
		std::cout << "[Proxy] Loading bitmap\n";
		if (m_FileName.empty()) {
			m_pBitmap->Load();
		}
		else {
			m_pBitmap->Load(m_FileName);
		}
		m_Loaded = true;
	}
	else {
		std::cout << "\n[Proxy] Display No Loading bitmap\n";
	}
	m_pBitmap->Display();
}

void BitmapProxy::Load() {
	//Don't load here
	m_FileName.clear();
	m_Loaded = false;
}

void BitmapProxy::Load(const std::string& fileName) {
	//Don't load here
	m_FileName = fileName;
	m_Loaded = false;
}