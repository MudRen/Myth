//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;

#include <task.h>
void create()
{
        set_name("�ֻذ�", ({"lunhui bang", "bang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�ֻ�˾��������������ƽ���ֻذ�\n");
                set("unit", "��");
               set("owner_name","����ƽ");
               set("owner_id","wang fangping");
        }
}


