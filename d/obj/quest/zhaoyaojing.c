//Cracked by Roath
// literate.c

inherit ITEM; 
#include <task.h>

void create()
{
        set_name("������", ({"zhaoyao jing", "jing"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                
        set("long",
"һ����ɫͭ�Ƶ���������ʹ���ϵ��µ���ħ����޴����Ρ�\n");
        set("material", "steel");
        set("owner_name", "�");
          set("owner_id", "li jing");
                }
}

