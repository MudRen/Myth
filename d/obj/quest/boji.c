//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
       set_name("������",({"zhu boji"}));
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long","�������ӱ�֯��������\n");
                set("unit", "��");
          set("owner_name", "������ʿ");
          set("owner_id", "li shi");
        }
}

