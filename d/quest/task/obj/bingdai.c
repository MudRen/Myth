//By waiwai@mszj 2000/12/02

#include <ansi.h>
inherit ITEM;
#include <task.h>

void create()
{
        set_name(HIW"����"NOR, ({"bing dai" ,"dai"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",   "һ������װ����Ĵ��ӡ�\n");
                set("unit", "��");
                              set("owner_name","��������");
                            set("owner_id","dapeng mingwang");
        }
}


