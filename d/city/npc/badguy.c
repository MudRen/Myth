/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
//Created by waiwai@2000/11/13

#include <ansi.h>

inherit NPC;
void create()
{
        set_name("�����ϲ�", ({ "dizhu laochai", "dizhu", "laochai" }) );
        set("long",CYN
"һ�������˰̼Ӻ���ļһ�,ר�Ÿ�եȡ����Ѫ���Ĺ����������ﻹɱ��Խ������������\n"NOR);
        set("attitude", "aggressive");
        set("per", 1);
        set("str", 40);
        set("combat_exp", 100000+random(4000000));
        set("bellicosity", 10000);
        set("chat_chance", 30);
        set("chat_msg", ({HIB
                "�����ϲ�ȵ�����������ҪǮ��Ҫ������\n"NOR,
                HIB"�����ϲ�Ц����С����ȥ���ɣ�\n"NOR,
		(: random_move :),
        }) );

	set("kee", 3000);
	set("sen", 3000);
	set("max_kee", 1500);
	set("max_sen", 1500);
	set("force", 1500);
	set("max_force", 1500);
	set("food", 1500);
	set("water", 1500);

        set_skill("unarmed", 100+random(200));
        set_skill("blade", 100+random(200));
        set_skill("parry", 100+random(200));
        set_skill("dodge", 100+random(200));
        set_skill("move", 100+random(200));
        set_skill("stealing", 600);

        set_temp("apply/attack", 170);
        set_temp("apply/defense", 170);
        set_temp("apply/armor", 170);
        set_temp("apply/damage", 130+random(400));
        set_temp("apply/dodge", 100);
	set("zombie",1);
	set("no_blade", 1);//���±���
	set("no_poison", 1);//�����ö�

        setup();

        carry_object("/obj/cloth/yexing")->wear();
        carry_object("/obj/weapon/guiblade")->wield();
}

// �����ܱȻ�
int accept_fight (object ob) { return 0; } 

void kill_ob (object ob) 
{ 
	set_temp("my_killer",ob); 
	::kill_ob(ob); 
} 

void die()
{
	int k;
	object ob;
	ob = query_temp("last_damage_from");

     ob->add("daoxing",800);
     ob->add("combat_exp",800);
     ob->add("potential",500);
     ob->add_temp("killbad",1);
     message("system",YEL"���{�Ի��ڡ�˳�������˵ "WHT+log_id(ob)+NOR YEL" ɱ�������ϲ�Ϊ��������õ��˹ٸ�����������\n"NOR,users());    
     tell_object (ob,WHT"\n��Ӯ���� 800 ����ѧ��200 ����У�500 ��Ǳ�ܣ�\n"NOR);

	k = ob->query_temp("killbad");
	if( k >= 5) {
		ob->add("potential",k*800);
		ob->delete_temp("killbad");
	message("system",YEL"���{�Ի��ڡ�˳��������� "WHT+log_id(ob)+NOR YEL" ����ɱ�������ϲ�Ϊ��������õ����⽱��"HIR+k*800+NOR YEL"��Ǳ�ܣ�\n"NOR,users());    
	tell_object (ob,HIG"\n����������ɱ�������ϲ�Ϊ������õ��˶��⽱��"+(k*800)+"��Ǳ�ܣ�\n"NOR);
	}

      ::die();
}

void unconcious() { die(); }
