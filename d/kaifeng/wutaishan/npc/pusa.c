

inherit NPC;

void create()
{
   set_name("��������", ({ "wenshu pusa", "pusa", "pu sa", "wenshu" }));
   set("title", "��̴������");   
   set("long", @LONG
    
�������������˷��ӣ���ʦ����Ĳ�ᣩ֮�����������ӡ���˵
��̨ɽ�����������ģ����Ҳ������̨ɽ�����ǽ����ɽ����
���쳣���� �������ˮ�ɱ��������ɰ��ʯ�����������ѵ���
ũ�����޷���ׯ�ڡ��ڴ˴��̵������������Ӷ������������
����һ������ʯ������һ��ɽ�Ⱥ����ɽ���̱�־һ������
�ޱȵĵط����Ӵ���������Ҳ���ڴ���š�
LONG);
   set("gender", "����");
   set("age", 55);
   set("per", 35);
   set("attitude", "friendly");
   set("max_kee", 3000);
   set("max_gin", 3000);
   set("max_sen", 3500);
   set("force", 2000);
   set("max_force", 2000);
   set("force_factor", 100);
   set("max_mana", 3500);
   set("mana", 3500);
   set("mana_factor", 200);
   set("combat_exp", 1000000);

        set("eff_dx", 400000);
        set("nkgain", 2000);

   set_skill("literate", 200);
   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("unarmed", 200);
   set_skill("jienan-zhi", 200);
   set_skill("dodge", 200);
   set_skill("staff", 200);
   set_skill("lunhui-zhang", 200);
   set_skill("lotusmove", 200);
   set_skill("parry", 200);
   set_skill("force", 200);
   set_skill("lotusforce", 200);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("staff", "lunhui-zhang");
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
  }) );

   setup();

   carry_object("/obj/money/gold");
      carry_object("/d/obj/cloth/hufa-jiasha")->wear();
}

