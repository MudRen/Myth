//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("��������", ({ "toothdice","dice" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "һ���������ӣ��ý�ۿ��ŵ㣬Ӧ����������\n");
                set("unit", "��");
                set("owner_name", "С�ܼ�");
          set("owner_id", "guan jia");
                
        }
        
        setup();
}

