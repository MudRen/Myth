#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIY"�����ǽ�"NOR, ({ "jinjing sword" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                       set("material", "iron");
 set("long", "һ��ب���񽣡�\n");
                  }
        init_sword(15);
        setup();
}
