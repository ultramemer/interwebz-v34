namespace ValveSDK
{
	enum OverrideType_t
	{
		OVERRIDE_NORMAL = 0,
		OVERRIDE_BUILD_SHADOWS,
		OVERRIDE_DEPTH_WRITE,
		OVERRIDE_WHATEVER
	};

	struct DrawModelState_t
	{
		studiohdr_t*			m_pStudioHdr;
		PVOID					m_pStudioHWData;
		PVOID					m_pRenderable;
		const matrix3x4_t		*m_pModelToWorld;
		int						m_decals;
		int						m_drawFlags;
		int						m_lod;
	};

	struct ModelRenderInfo_t
	{
		int flags;
		PVOID *pRenderable;
		unsigned short instance;
		int entity_index;
		const model_t *pModel;
		Vector origin;
		Vector angles;
		int skin;
		int body;
		int hitboxset;
		const matrix3x4_t *pModelToWorld;
		const matrix3x4_t *pLightingOffset;
		const Vector *pLightingOrigin;

		ModelRenderInfo_t()
		{
			pModelToWorld = NULL;
			pLightingOffset = NULL;
			pLightingOrigin = NULL;
		}
	};

	enum MaterialVarFlags_t
	{
		MATERIAL_VAR_DEBUG					  = (1 << 0),
		MATERIAL_VAR_NO_DEBUG_OVERRIDE		  = (1 << 1),
		MATERIAL_VAR_NO_DRAW				  = (1 << 2),
		MATERIAL_VAR_USE_IN_FILLRATE_MODE	  = (1 << 3),

		MATERIAL_VAR_VERTEXCOLOR			  = (1 << 4),
		MATERIAL_VAR_VERTEXALPHA			  = (1 << 5),
		MATERIAL_VAR_SELFILLUM				  = (1 << 6),
		MATERIAL_VAR_ADDITIVE				  = (1 << 7),
		MATERIAL_VAR_ALPHATEST				  = (1 << 8),
		MATERIAL_VAR_MULTIPASS				  = (1 << 9),
		MATERIAL_VAR_ZNEARER				  = (1 << 10),
		MATERIAL_VAR_MODEL					  = (1 << 11),
		MATERIAL_VAR_FLAT					  = (1 << 12),
		MATERIAL_VAR_NOCULL					  = (1 << 13),
		MATERIAL_VAR_NOFOG					  = (1 << 14),
		MATERIAL_VAR_IGNOREZ				  = (1 << 15),
		MATERIAL_VAR_DECAL					  = (1 << 16),
		MATERIAL_VAR_ENVMAPSPHERE			  = (1 << 17),
		MATERIAL_VAR_NOALPHAMOD				  = (1 << 18),
		MATERIAL_VAR_ENVMAPCAMERASPACE	      = (1 << 19),
		MATERIAL_VAR_BASEALPHAENVMAPMASK	  = (1 << 20),
		MATERIAL_VAR_TRANSLUCENT              = (1 << 21),
		MATERIAL_VAR_NORMALMAPALPHAENVMAPMASK = (1 << 22),
		MATERIAL_VAR_NEEDS_SOFTWARE_SKINNING  = (1 << 23),
		MATERIAL_VAR_OPAQUETEXTURE			  = (1 << 24),
		MATERIAL_VAR_ENVMAPMODE				  = (1 << 25),
		MATERIAL_VAR_SUPPRESS_DECALS		  = (1 << 26),
		MATERIAL_VAR_HALFLAMBERT			  = (1 << 27),
		MATERIAL_VAR_WIREFRAME                = (1 << 28),

		// NOTE: Only add flags here that either should be read from
		// .vmts or can be set directly from client code. Other, internal
		// flags should to into the flag enum in IMaterialInternal.h
	};

	class IMaterial
	{
	public:
		virtual const char *GetName() const = 0;
		virtual const char *GetTextureGroupName() const = 0;
		virtual int vfunc02() = 0;
		virtual int vfunc03() = 0;
		virtual int vfunc04() = 0;
		virtual int vfunc05() = 0;
		virtual int vfunc06() = 0;
		virtual int vfunc07() = 0;
		virtual int vfunc08() = 0;
		virtual int vfunc09() = 0;
		virtual int vfunc10() = 0;
		virtual int vfunc11() = 0;
		virtual void IncrementReferenceCount( void ) = 0;
		virtual void DecrementReferenceCount( void ) = 0;
		virtual int vfunc14() = 0;
		virtual int vfunc15() = 0;
		virtual int vfunc16() = 0;
		virtual int vfunc17() = 0;
		virtual int vfunc18() = 0;
		virtual int vfunc19() = 0;
		virtual int vfunc20() = 0;
		virtual int vfunc21() = 0;
		virtual int vfunc22() = 0;
		virtual int vfunc23() = 0;
		virtual int vfunc24() = 0;
		virtual int vfunc25() = 0;
		virtual int vfunc26() = 0;
		virtual int vfunc27() = 0;
		virtual int vfunc28() = 0;
		virtual void AlphaModulate(float alpha) = 0;
		virtual void ColorModulate(float r, float g, float b) = 0;
		virtual void SetMaterialVarFlag(MaterialVarFlags_t flag, bool on) = 0;
		virtual bool GetMaterialVarFlag(MaterialVarFlags_t flag) const = 0;
		virtual int vfunc31() = 0;
		virtual int vfunc32() = 0;
		virtual int vfunc33() = 0;
		virtual int vfunc34() = 0;
		virtual int vfunc35() = 0;
		virtual int vfunc36() = 0;
		virtual int vfunc37() = 0;
		virtual int vfunc38() = 0;
		virtual int vfunc39() = 0;
		virtual int vfunc40() = 0;
		virtual int vfunc41() = 0;
		virtual int vfunc42() = 0;
		virtual int vfunc43() = 0;
		virtual bool IsErrorMaterial() = 0;
		virtual int vfunc44() = 0;
		virtual float GetAlphaModulation() = 0;
		virtual void GetColorModulation(float *r, float *g, float *b) = 0;
	};

	class Color
	{
	public:
		Color(int r,int g,int b,int a)
		{
			_color[0] = (unsigned char)r;
			_color[1] = (unsigned char)g;
			_color[2] = (unsigned char)b;
			_color[3] = (unsigned char)a;
		}

		unsigned char _color[4];
	};

	typedef unsigned short MaterialHandle_t;

	class IMaterialSystem
	{
	public:
		void UncacheMaterials()
		{
			typedef void(__thiscall* OriginalFn)(PVOID);
			getvfunc<OriginalFn>(this, 36)(this);
		}

		IMaterial *CreateMaterial(const char *pMaterialName, PVOID pVMTKeyValues)
		{
			typedef IMaterial*(__thiscall* OriginalFn)(PVOID,const char*,PVOID);
			return getvfunc<OriginalFn>(this, 123)(this,pMaterialName,pVMTKeyValues);
		}

		MaterialHandle_t FirstMaterial()
		{
			typedef MaterialHandle_t(__thiscall* OriginalFn)(PVOID);
			return getvfunc<OriginalFn>(this, 23)(this);
		}

		IMaterial *GetMaterial(MaterialHandle_t h)
		{
			typedef IMaterial*(__thiscall* OriginalFn)(PVOID,MaterialHandle_t);
			return getvfunc<OriginalFn>(this, 26)(this,h);
		}

		int	GetNumMaterials()
		{
			typedef int(__thiscall* OriginalFn)(PVOID);
			return getvfunc<OriginalFn>(this, 34)(this);
		}
	};

	class IVModelRender
	{
	public:
		virtual int		vfunc00() = 0;
		virtual void	ForcedMaterialOverride( IMaterial *newMaterial ) = 0;
		virtual bool	vfunc02() = 0;
		virtual int		vfunc03() = 0;
		virtual int		vfunc04() = 0;
		virtual int		vfunc05() = 0;
		virtual int		vfunc06() = 0;
		virtual int		vfunc07() = 0;
		virtual int		vfunc08() = 0;
		virtual int		vfunc09() = 0;
		virtual int		vfunc10() = 0;
		virtual int		vfunc11() = 0;
		virtual int		vfunc12() = 0;
		virtual int		vfunc13() = 0;
		virtual int		vfunc14() = 0;
		virtual int		vfunc15() = 0;
		virtual int		vfunc16() = 0;
		virtual int		vfunc17() = 0;
		virtual int		vfunc18() = 0;
		virtual int DrawModelExecute(ModelRenderInfo_t &pInfo) = 0;
	};

	class IVRenderView
	{
	public:
		virtual void vfunc00() = 0;
		virtual void vfunc01() = 0;
		virtual void vfunc02() = 0;
		virtual void vfunc03() = 0;

		virtual void SetBlend( float blend ) = 0;
		virtual float GetBlend( void ) = 0;

		virtual void SetColorModulation( float const* blend ) = 0;
		virtual void GetColorModulation( float* blend ) = 0;
	};

	class ISurface
	{
	public:
		void DrawSetColor(int r, int g, int b, int a)
		{
			typedef void(__thiscall* OriginalFn)(PVOID, int, int, int, int);
			getvfunc<OriginalFn>(this, 11)(this, r, g, b, a);
		}

		void DrawFilledRect(int x0, int y0, int x1, int y1)
		{
			typedef void(__thiscall* OriginalFn)(PVOID, int, int, int, int);
			getvfunc<OriginalFn>(this, 12)(this, x0, y0, x1, y1);
		}

		void DrawLine(int x0, int y0, int x1, int y1)
		{
			typedef void(__thiscall* OriginalFn)(PVOID, int, int, int, int);
			getvfunc<OriginalFn>(this, 15)(this, x0, y0, x1, y1);
		}

		void DrawSetTextFont(unsigned long font)
		{
			typedef void(__thiscall* OriginalFn)(PVOID, unsigned long);
			getvfunc<OriginalFn>(this, 17)(this, font);
		}
		 
		void DrawSetTextColor(int r, int g, int b, int a)
		{
			typedef void(__thiscall* OriginalFn)(PVOID, int, int, int, int);
			getvfunc<OriginalFn>(this, 19)(this, r, g, b, a);
		}

		void DrawSetTextPos(int x, int y)
		{
			typedef void(__thiscall* OriginalFn)(PVOID, int, int);
			getvfunc<OriginalFn>(this, 20)(this, x, y);
		}

		void DrawPrintText(const wchar_t *text, int textLen)
		{
			typedef void(__thiscall* OriginalFn)(PVOID, const wchar_t *, int, int);
			return getvfunc<OriginalFn>(this, 22)(this, text, textLen, 0);
		}

		unsigned long CreateFont()
		{
			typedef unsigned int(__thiscall* OriginalFn)(PVOID);
			return getvfunc<OriginalFn>(this, 64)(this);
		}

		void SetFontGlyphSet(unsigned long &font, const char *windowsFontName, int tall, int weight, int blur, int scanlines, int flags)
		{
			typedef void(__thiscall* OriginalFn)(PVOID, unsigned long, const char*, int, int, int, int, int, int, int);
			getvfunc<OriginalFn>(this, 65)(this, font, windowsFontName, tall, weight, blur, scanlines, flags, 0, 0);
		}

		void GetTextSize(unsigned long font, const wchar_t *text, int &wide, int &tall)
		{
			typedef void(__thiscall* OriginalFn)(void*, unsigned long font, const wchar_t *text, int &wide, int &tall);
			getvfunc<OriginalFn>(this, 72)(this, font, text, wide, tall);
		}
	};
}