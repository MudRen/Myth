#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
        set_name(HIY"��˿���ڱ�"NOR, ({ "jinsi bian" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                       set("material", "gold");
 set("long", "������������׷�����������ʹ�õ�һ���ݺὭ�������޵еĶ��ű��С�\n");
                  }
        init_whip(15);
        setup();
}
