//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(HIR "����" NOR, ({"yin zhen", "zhen"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����õ����롣\n");
                set("unit", "��");
               set("owner_name","��Ԩ����");
               set("owner_id","wuyuan daozhang");
        }
}



