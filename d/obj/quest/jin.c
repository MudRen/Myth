//Cracked by Roath


// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("�ֽ�", ({"shou jin", "jin"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����ֽ�ɾȹ��ش��˵����ء�\n");
                set("unit", "��");
               set("owner_name","����");
               set("owner_id","qin qiong");
        }
}


