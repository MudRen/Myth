//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIW"��ƥ"NOR, ({"bu pi", "bu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һƥ�ײ���\n");
                set("unit", "ƥ");
               set("owner_name","Ҧ����");
               set("owner_id","yao fugui");
        }
}

