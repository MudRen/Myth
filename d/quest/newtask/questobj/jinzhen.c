#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("【金针度世】", ({ "jinzhen dushi" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "无极剑派宗师傅青主所著秘籍。\n");
          }

    setup();
}
