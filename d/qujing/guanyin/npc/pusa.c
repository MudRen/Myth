inherit NPC;
inherit F_MASTER;

int do_drop(object, object);

void create()
{
   set_name("��������", ({ "guanyin pusa", "guanyin", "pusa" }));
   set("title", "�ȿ���Ѵ�ȴ�");
   set("long", @LONG
��Բ�ĵ£���������ü��С�£�����˫�ǡ�����������
ޥ�԰����١���������٤ɽ�ϴȱ�������������������
LONG);
   set("gender", "Ů��");
   set("age", 35);
   set("attitude", "peaceful");
   set("rank_info/self", "ƶɮ");
   set("rank_info/respect", "��������");
   set("class", "bonze");
   set("str",24);
   set("per",100);//means no rong-mao description.
   set("max_kee", 5000);
   set("max_gin", 5000);
   set("max_sen", 5000);
   set("force", 4000);
   set("max_force", 2000);
   set("force_factor", 145);
   set("max_mana", 3000);
   set("mana", 6000);
   set("mana_factor", 150);
   set("combat_exp", 2000000);
   create_family("�Ϻ�����ɽ", 1, "����");
   setup();
}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/guanyin") == "done")
    return;
  if (who->query_temp("obstacle/guanyin_lingxuzi") < 1 ||
      who->query_temp("obstacle/guanyin_xiushi") < 1 ||
      who->query_temp("obstacle/guanyin_yuanzhu") < 1 ||
      who->query_temp("obstacle/guanyin_heihan") < 1)
    return;
  i = random(700);
  who->add("obstacle/number",1);
  who->set("obstacle/guanyin","done");
  who->add("daoxing",i+4000);
  command("chat "+who->query("name")+"�ڷ綴�շ����ܹ֣�Ѱ�ؽ�����£�");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(4)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}
