#include <weapon.h>
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(HIC"青魔手"NOR, ({ "qingmo shou" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                 set("material", "cloth");
                set("armor_prop/armor", 2);
 set("long", "一种铁手套，武林中最霸道的兵器之一，在百晓生的《兵器谱》中排名第九。\n");
                       }
        setup();
}
