//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
    set_name("��ɱ��¼", ({ "ansha baolu", "snshabaolu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ�ż����˽�����ͷ��������İ�ɱ������\n");
            set("owner_name", "����");
          set("owner_id", "hua ren");
          }
    setup();
}

