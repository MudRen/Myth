//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
       set_name("��������",({"yuhu"}));
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long","���Ǵ��ƹ��󳼶���޵����ˡ�\n");
                set("unit", "��");
          set("owner_name", "�����");
          set("owner_id", "du ruhui");
        }
}

