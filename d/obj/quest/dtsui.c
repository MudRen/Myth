//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("������",({ "ditiansui" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֽ");
                set("material", "paper");
                set("long", "����һ�ż������������������������ֽ\n");
                set("owner_name","Ԭ�س�");
                     set("owner_id","yuan shoucheng");
        }
}

