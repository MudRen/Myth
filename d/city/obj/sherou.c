/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// Last modified by waiwai@2002/12/05

inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("����", ({ "she rou", "rou" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ���տ�������������⣬��ʮ���ѵõ���ζ��\n");
		set("unit", "��");
		set("value", 2000);
		set("food_remaining", 3);
		set("food_supply", 20);
        }
	setup();
}

