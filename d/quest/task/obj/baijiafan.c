//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(BLK "�ټҷ�" NOR, ({"baijia fan", "fan"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��Ѱ���˼ҳ�ʣ�µķ��ˡ�\n");
                set("unit", "��");
               set("owner_name","��ؤ");
               set("owner_id","qi gai");
        }
}

