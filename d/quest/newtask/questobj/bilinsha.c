#include <weapon.h>
#include <ansi.h>
inherit THROWING;
void create()
{
        set_name(HIG"����ɰ"NOR, ({ "bilin sha" }) );
        set_weight(30); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                       set("material", "iron");
 set("long", "��Ŀ���˻��ŷ�����������ɽ���룬ȡ��Ĺ�����˵İ׹��׻𣬻����𾫻����������ɵİ�����\n");
                  }
           setup();
}
