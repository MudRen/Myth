//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>
void create()
{
        set_name(HIY"����", ({"shao zi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�Ѹ��Ƶ������õ����ӡ�\n");
                set("unit", "��");
               set("owner_name","�Ƴ�ɮ");
                set("owner_id","zhangchu seng");
        }
}


