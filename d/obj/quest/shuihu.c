//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("ˮ��", ({"shui hu", "hu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�Ž����ڻ���ɽ����ʢˮ�ļһ\n");
                set("unit", "��");
               set("owner_name","�Ž���");
               set("owner_id","ba jiangjun");
        }
}


