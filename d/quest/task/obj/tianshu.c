//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(HIW "��������" NOR, ({"baizi tianshu", "tianshu"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "ֻ��Ԭ�سϿ��ö������顣\n");
                set("unit", "��");
                set("owner_name","Ԭ�س�");
               set("owner_id","yuan shoucheng");
        }
}

