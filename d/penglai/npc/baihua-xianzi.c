//Cracked by Roath

//baihua xianzi
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name("�ٻ�����", ({"baihua xianzi", "baihua", "xianzi"}));
       set("long",@LONG
����ĸ�ĵ��ӡ�����ĸ֮������˾������������Ⱥ��֮����
�����϶����������ݺ������ط����������������������
��㺮�����������ơ��ٻ���Ϊ�����˼䣬��һ��Һ��
LONG);

       set("title", "Ⱥ��֮��");
       set("gender", "Ů��");
       set("age", 20);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "�ɹ�");
       set("per", 30);
        set("int", 30);
       set("max_gin", 600);
  set("max_sen",5000);
  set("max_kee",5000);
   set("force",4000);
       set("max_force", 2500);
       set("force_factor", 200);
       set("max_mana", 3000);
       set("mana", 6000);
       set("mana_factor", 250);
       set("combat_exp", 3000000);
       set("daoxing", 2500000);


   set("inquiry",(["�ٻ���":"��ϧ����Ƨ�����⣬�滨Ʒ�ֲ�ȫ�������ھ��м���(add)�����ʻ����˾Ʋ�����ɡ�",]));
        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 100);
       set_skill("unarmed", 180);
       set_skill("dodge", 70);
       set_skill("force", 80);
       set_skill("parry", 80);
       set_skill("spells", 100);
       set_skill("moonshentong", 80);
       set_skill("baihua-zhang", 200);
       set_skill("moonforce", 80);
       set_skill("moondance", 70);
       set_skill("whip",80);
       set_skill("jueqingbian",80);
       map_skill("spells", "moonshentong");
       map_skill("unarmed", "baihua-zhang");
       map_skill("force", "moonforce");
       map_skill("dodge", "moondance");

           set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "arrow" :),
               (: cast_spell,"mihun" :),
               (: cast_spell,"shiyue" :),
        }) );
       create_family("�¹�", 2, "����");
       setup();

       carry_object("/d/moon/obj/luoyi")->wear();
       carry_object("/d/quest/longzhu/obj/jingshi7");
     carry_object("/d/obj/book/makeupbook");
      carry_object("/d/shendian/babu/obj/xiangjing");
       if (clonep()) carry_object("/d/obj/flower/rose")->wear();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="Ů��")){
           command("shake");
           command("say �����¹�ֻ��Ůͽ����λ" +
RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
           return;}
        if ( !ob->query_temp("denied_by_chang_e")){
          command("shake");
        command("say ��ֻ����Ե֮�ˣ���λ" +
RANK_D->query_respect(ob) + "����ȥ����϶�ɡ�\n");
        return;
}

        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ�����������¹�������\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}
