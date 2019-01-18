#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIY"½ð¾«ÓñÆÇ½£"NOR, ({ "jinjing sword" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "±ú");
                       set("material", "iron");
 set("long", "Ò»±úØ¨¹ÅÉñ½£¡£\n");
                  }
        init_sword(15);
        setup();
}
