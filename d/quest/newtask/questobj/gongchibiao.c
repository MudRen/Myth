#include <weapon.h>
inherit THROWING; 

void create()
{
        set_name("������", ({ "gongchi biao" }) );
        set_weight(30); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                 set("material", "iron");
                set("long", "����������Ϊһöö��С�񱡲�ͬ����Ǯ��\n");}
                init_throwing(15);
                setup();
}
