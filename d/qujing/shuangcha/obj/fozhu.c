//Cracked by Roath
#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
      set_name(YEL"̴ľ����"NOR,({"fo zhu","zhu"}));
      set("long","һ���ϵ�̴ľ���ɵķ��顣\n");
      if( clonep() )
                set_default_object(__FILE__);
        else {
      set("value",100);
      set("unit","��");
      set("weight",5000);
      set("armor_prop/armor",5);
      setup();
}
}
