//Cracked by Roath

// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
        set_name("���", ({"Zhu bi", "bi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����Ǳ�������\n");
                set("unit", "ֻ");
               set("owner_name",HIW"����"NOR);
               set("owner_id","cui jue");
        }
}


