//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;

#include <task.h>
void create()
{
      set_name("�����",({"fenglei jian","jian"}));
        set_weight(80);
        set("channel_id", "Ѱ�ﾫ��");
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("long","����ξ�ٹ��Ĺ��ñ�����\n");
                set("unit", "��");
           set("owner_name", "ξ�ٹ�");
           set("owner_id", "yuchi gong");
        }
}



