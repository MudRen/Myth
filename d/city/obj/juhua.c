/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// Last modified by waiwai@2002/12/05

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
         set_name(YEL"�ջ���"NOR, ({ "juhua jiu", "jiu" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("long", YEL"����һ���մɾƺ�������װ��"+name()+"��\n"NOR);
              set("unit", "��");
              set("value", 1000);
              set("max_liquid", 50);
        }

        set("liquid", ([
                "type": "water",
                 "name": "�ջ���",
                "remaining": 30,
        ]) );
}
