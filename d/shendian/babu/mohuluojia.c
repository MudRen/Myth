inherit NPC;
#include <ansi.h>
string ask_tianshen();
 string ask_done();

void create()
{
       set_name(HIR"Ħ������"NOR, ({"mohu luojia"}));
        set("long","һ���������������ͷ��\n");
       set("gender", "����");
       set("age", 20);
        set("title", HIB"�˲�����"NOR);
        set("int", 25);
       set("attitude", "heroism");
        set("combat_exp", 1200000);
  set("daoxing", 1500000);

        set("eff_dx", -500000);
        set("nkgain", 500);

       set("class","yaomo");
       set("per", 10);
        set("str", 30);
       set("max_kee", 1600);
       set("max_sen", 1600);
       set("force", 2000);
       set("max_force", 2000);
       set("force_factor", 100);
       set("max_mana", 1600);
       set("mana", 3000);
       set("mana_factor", 80);
        set_skill("huomoforce", 160);
        set_skill("pingtian-dafa", 160);
        set_skill("unarmed", 160);
        set_skill("dodge", 160);
        set_skill("force", 160);
        set_skill("parry", 200);
        set_skill("spells", 160);
        set_skill("fork", 200);
        set_skill("yueya-chan", 160);
        set_skill("moshenbu", 160);
        set_skill("moyun-shou", 160);
        map_skill("unarmed", "moyun-shou");
        map_skill("dodge", "moshenbu");
        map_skill("parry", "yueya-chan");
        map_skill("fork", "yueya-chan");
        create_family("���ƶ�", 2, "��");
        set("inquiry", ([
                "�����" : (: ask_tianshen :),
                "shendian" : (: ask_tianshen :),
                "done" : (: ask_done :),
                ]) );
        setup();
        carry_object("/d/qujing/bibotan/obj/moonstaff")->wield();
        carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
}
string ask_tianshen()
{
        object me = this_player();
    object mixin;
   if ( (string)me->query_temp("babu/mohuluojia") == "begin")
              return "�����͵�����\n";
        if ( (string)me->query_temp("babu/mohuluojia") == "done")
         return "�Ҳ����Ѿ�����������\n";
        if ( (string)me->query_temp("mohuluojia/mixin") == "done")
      return "���Ѿ�������Ŷ��\n";
  command("say ����֪������֮�������ﰡ��\n");
  command("hmm ");
  command("say ������Ҳ���ԣ����Ȱ��Ұ���������͸������ޡ�\n");
 me->set_temp("babu/mohuluojia","begin");
  mixin = new("/d/shendian/babu/obj/mixin");
  mixin->move(me);
 return "���������Ҫ�����������Ŷ��\n";
}
string ask_done()
{
     object me = this_player();
     if(me->query_temp("babu/mohuluojia") == "begin")
    {
    if(me->query_temp("mohuluojia/mixin") == "begin")
            return "�����͵�����\n";
  command("say �����ɵĲ���\n");
  command("say ��ȥ��������Ͱɣ�\n");
    me->set_temp("babu/mohuluojia","done");
    me->delete_temp("mohuluojia/mixin");
    return "ȥ��! \n";
    }
    else
    {
    return "���ʲô�ˣ�\n";
    }
}
