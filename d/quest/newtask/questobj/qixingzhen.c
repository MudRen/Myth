#include <weapon.h>

inherit THROWING; 
void create()
{
        set_name("����͸����", ({ "qixing zhen" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                 set("material", "iron");
                set("long", "���������������ڿ�ȸ��İԵ�������ϵ�����������ͯ�Ӵ��졣\n");}
                setup();
}
