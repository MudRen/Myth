//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(RED"ѹ����"NOR, ({ "hongbao" }) ); 
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("long", "һ��СС�ĺ������С����ѹ��Ǯ��\n");
            set("unit", "��"); 
            set("owner_name", "�Ϻ���");
          set("owner_id", "xifuhui boss");
          }
    setup();
}

