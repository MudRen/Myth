/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
// Last modified by waiwai@2002/12/05

inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("蛇肉", ({ "she rou", "rou" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一条烧烤得香喷喷的蛇肉，是十分难得的美味。\n");
		set("unit", "条");
		set("value", 2000);
		set("food_remaining", 3);
		set("food_supply", 20);
        }
	setup();
}

