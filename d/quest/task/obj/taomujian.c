//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>

void create()
{
        set_name(HIY"��ľ��"NOR, ({"taomu jian","jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", " ͸�ź���ı�����\n");
                set("unit", "��");
                 set("owner_name","Ԭ���");
               set("owner_id","yuan tiangang");
        }
}

