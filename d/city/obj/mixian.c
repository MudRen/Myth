/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// Last modified by waiwai@2002/12/05

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��������", ({"guoqiao mixian", "mixian"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ���������ڵ��ͽ����׷ۣ������������˹������ߡ�\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 10);
		set("food_supply", 20);
	}
}
