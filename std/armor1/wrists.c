/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
//Created by waiwai@2003/01/25 ����(������)

#include <armor.h>

inherit EQUIP;

void setup()
{
	if( clonep(this_object()) ) return;

	//û���κβ�������ĬȻΪϵͳ����ֵ
	if( !query("armor_prop/armor") && !query("armor/max_armor") )
		set("armor_prop/armor",PROP_WRISTS);

	//�ų���������������־��,����LIMIT��������Ϊ���Ʋ�����Ч
	if( !query("combine") && query("LIMIT")) {
	if( query("armor_prop/armor") > PROP_WRISTS )
	          set("armor_prop/armor",PROP_WRISTS);
	}

	if( !query("armor/max_armor") )
		set("armor/max_armor",query("armor_prop/armor"));
	else
		set("armor_prop/armor",query("armor/max_armor"));

	set("armor_type", TYPE_WRISTS);
	if( !query("armor_apply/dodge")
	&&	weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );
}
