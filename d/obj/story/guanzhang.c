// story:zagang.c

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "������˵�������ڳ�����һ���������˼�ʮ����������������",
        "�ŷɣ�������Ȼ���ҳ��������裬�����Ǹ�ʤ������",
        "�����������治�����ܻ���û�У�",
        "�ŷ���������һ�������裬�������⻹�����ء�",
        "���𣺺ٺ٣�",
        "�ŷɣ��ޣ����磬�м�����˵�ˣ���˵�����Ժ��˵���ɫ��䡣",
        "���𣺣���ô�䣿",
        "�ŷɣ����ң�����������£����෴�ķ�����",
        "���𣺿������Ҳ���Ҫ��������ˣ�",
        "�ŷɣ�Ӧ�á�",
        "����ݺݵİ����������˳�ȥ��",
        (: give_gift :),
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
        STORY_D->give_gift("/clone/gift/shenliwan", 1,
                           HIM "\n��ž����һ��һö�������������ǰ��\n\n" NOR);
        return 0;
}
