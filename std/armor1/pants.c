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
		set("armor_prop/armor",PROP_PANTS);

	//�ų���������������־��,����LIMIT��������Ϊ���Ʋ�����Ч
	if( !query("combine") && query("LIMIT")) {
	if( query("armor_prop/armor") > PROP_PANTS )
		set("armor_prop/armor",PROP_PANTS);
	}

	if( !query("armor/max_armor") )
		set("armor/max_armor",query("armor_prop/armor"));
	else
		set("armor_prop/armor",query("armor/max_armor"));

	set("armor_type", TYPE_PANTS);
	if( !query("armor_apply/dodge")
	&&	weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );
}

void init() {	add_action("do_tear", "tear"); }

int do_tear(string str)
{
	object ob;

	if( !id(str) ) return 0;

	if( (string)query("material") != "cloth" 
		|| (string)query("material") != "pants" )
		return notify_fail(	WHT"��ֻ��˺һ�㲼��(���»��߿���)���·���\n"NOR);

	if( (string)query("material") == "cloth" ) {
	if( (int)query("teared_count") >= 4 )
		return notify_fail( name() + "����ڣ������Ѿ�û�ж���Ĳ���˺�ˡ�\n");
	}

	if( (string)query("material") == "pants" ) {
	if( (int)query("teared_count") >= 4 )
		return notify_fail( name() + "�Ŀ�ţ������Ѿ�û�ж���Ĳ���˺�ˡ�\n");
	}

	message_vision("$N��" + name() + "˺��һ��������\n", this_player() );
	add("teared_count", 1);
	ob = new("/obj/bandage");
	ob->set_name("��" + name() + "˺�µĲ���", ({ "cloth piece", "piece", "cloth" }) );
	if( !ob->move(this_player()) )
		ob->move(environment(this_player()));
	return 1;
}

