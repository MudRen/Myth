#include <ansi.h>

int pk();
int nopk();
int gift();
int back();
int bainiao_jian();
int fengbo_cha();
int lunhui_zhang();

inherit NPC;

void create()
{
  set_name("����Ů��", ({ "ziyou nushen", "nushen"}));
  set("title", HIC"������"NOR);
// 17    set("long", HIW"\nһλ������ֵ�Ů�ӣ�������Ť������֫��\n�־����ɻ�ѣ��й������ɵ��£�������������\n"NOR+HIC"\n ask nushen about pk ѡ��У˵ĵ�·��\n ask nushen about nopk ѡ��ΣϣУ˵ĵ�·��\n ask nushen about gift ��ȡȡ����ɴ����칬���صĽ�����\n ask nushen about back ���������ѡ����һ������ѡ��Ļ��ᡣ\n\n"NOR);
  set("long", HIW"\nһλ������ֵ�Ů�ӣ�������Ť������֫��\n�־����ɻ�ѣ��й������ɵ��£�������������\n"NOR+HIC"\n ask nushen about pk ѡ��У˵ĵ�·��\n ask nushen about nopk ѡ��ΣϣУ˵ĵ�·��\n ask nushen about back ���������ѡ����һ������ѡ��Ļ��ᡣ\n\n"NOR);
  set("color", HIW);
  set("gender", "Ů��");
  set("age", 16);
  set("attitude", "heroism");
  set("per", 32);
  set("combat_exp", 2400000);
  set("daoxing", 6800000);
  set("inquiry", ([ //
  "name" : "�Ҿ����߿�վ������Ů�������ѡ��pk�����ߡ�nopk�����������Ժ��������\n",
  "here" : "�����ѡ��pk�����ߡ�nopk�����������Ժ��������\n",
  "PK"   : (:pk:),
  "pk"   : (:pk:),
  "NOPK" : (:nopk:),
  "nopk" : (:nopk:),
  "NO PK" : (:nopk:),
  "no pk" : (:nopk:),
  /*
  "gift" : (:gift:),
  "����" : (:gift:),
  */
  "back" : (:back:),
  "����" : (:back:),
  ]));
  setup();
}

int pk()
{
    object who = this_player();
    if (who->query("pk")=="pk")
    {
        tell_object(who,"���Ѿ�ѡ���� PK ������·! \n");
        return 1;
    }
    else
    {
        message_system("����Ů��"+who->name()+"�Ѿ�ѡ����PK������·�������֪�ա�");
        message_vision("����Ů���ھ����ѣ���$Nͷ������һ������$N˵�����������Ѿ�ѡ����PK������·���Ժ����Ϊ֮������\n",who);
        who->set("ziyouchoose","pk");
        who->set("pk","pk");
        return 1;
    }
}

int nopk()
{
    object who = this_player();

    if (this_player()->query("PKS")>3)
    {
        tell_object(who,"��ɱ�˹��࣬�޷���ѡ�� NOPK ��\n");
        return 1;
    }
    else
    {
        message_system("����Ů��"+who->name()+"�Ѿ�ѡ����NOPK������·������Ժ�Ҫ��Ϊ�����ˡ�");
        message_vision("����Ů���ھ����ѣ���$Nͷ������һ������$N˵�����������Ѿ�ѡ����NOPK������·���Ժ�������˵�æ����\n",who);
        who->set("ziyouchoose","nopk");
        who->set("nopk","nopk");
        who->set("ziyou","got");
        return 1;
    }
}

int back()
{
    object who = this_player();

    if (who->query("PKS") > 0)
    {
        tell_object(who,"����Ů�����$N˵�����˶�ɱ���ˣ���Ҫ��ô������\n");
        return 1;
    }
    if (who->query("ziyouback")=="got")
    {
        message_vision("����Ů�����$N˵������������Ѿ�����һ���ˣ����˻��ǲ�Ҫ̫�����޳��ã���\n",who);
        return 1;
    }
    else
    {
        message_vision("����Ů���ھ����ѣ���$Nͷ������һ������$N˵�����������Ѿ�����ѡ�����������·����\n",who);
        who->delete("ziyouchoose");
        who->set("ziyouback","got");
        PKMANAGER_D->change_choose(who);
        return 1;
    }
}
