//Cracked by Roath
// jiading.c �Ҷ�
// writen by kittt

inherit NPC;

void create()
{
        set_name("�Ҷ�", ({"jia ding", "jia", "ding"}));
        set("gender", "����");
        set("age", 27);
        set("long", 
        "����һ������������ݵļҶ��� \n" );
        set("shen_type", -1);
        
        set_skill("sword", 40);
        set_skill("dodge", 40);
      set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set("combat_exp", 2000);
                
        setup();
        
        carry_object(CLOTH_OB("cloth"))->wear();
        carry_object(WEAPON_OB("changjian"))->wield();
}
