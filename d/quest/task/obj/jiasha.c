//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <task.h>
#include <ansi.h>

void create()
{
          set_name(HIW"����"HIY"����"NOR, ({"jinlan jiasha"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����������������֮�������ģ���˵���Ͽ�����ֻء�\n");
                set("unit", "��");
                 set("owner_name","��������");
                set("owner_id","guanyin pusa");
        }
}

