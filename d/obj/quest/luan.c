//Cracked by Roath

// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("¿��", ({"lu an", "an"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����Ϊ�Ź��ϵ�Сë¿�������ġ�\n");
                set("unit", "��");
               set("owner_name","�Ź���");
               set("owner_id","zhang guolao");
        }
}


