//By waiwai@mszj 2000/12/02


inherit ITEM;
#include <task.h>
#include <ansi.h> 

void create()
{
        set_name(YEL "�������" NOR, ({"datie chui"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�Ѵ����õĴ��ӡ�\n");
                set("unit", "��");
            set("owner_name","������"); 
            set("owner_id","blacksmith"); 
        }
}


