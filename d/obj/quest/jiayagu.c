//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
    set_name(HIM"������"NOR, ({ "jiaya gu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("long", "һ�����Ƶļ�����\n");
            set("unit", "��"); 
            set("owner_name", "���Ϻ��");
          set("owner_id", "xia po");
          }

    setup();
}

