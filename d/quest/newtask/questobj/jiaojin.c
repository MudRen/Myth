#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
        set_name("�޽�", ({ "jiao jin" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                       set("material", "silk");
 set("long", "�������ƶ��ɵ����ӣ�������ǿ�����������ܳ��ϡ�\n");
                  }
           setup();
}
