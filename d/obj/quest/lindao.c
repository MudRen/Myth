//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("���ֵ�", ({ "lindao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 60);
                set("jungle",1);
                set("material", "iron");
            set("long", "����һѰ���Ŀ��ֵ���ר��������С���͹�ľ��\n"); 
                set("owner_name", "�����ʿ");
          set("owner_id", "taoist");
                
        }
        
        setup();
}

