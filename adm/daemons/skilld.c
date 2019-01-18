// skilld.c
// for sjsh lib mudring Nov/24/2002

inherit F_DBASE;
inherit F_CLEAN_UP;


string *path = ({ // ����ʹ�õ�skillsĿ¼
    "/daemon/skill/",           // ����skillsĿ¼
    "/daemon/skill/basic/",     // ����skillsĿ¼
    "/daemon/skill/quest/",     // ����skillsĿ¼
    "/daemon/skill/lunhui/",    // �ֻ�skillsĿ¼
    "/daemon/skill/other/",     // ����skillsĿ¼
    "/daemon/skill/bonze/",     // �Ϻ�����ɽ bonze
    "/daemon/skill/dragon/",    // �������� dragon
    "/daemon/skill/fighter/",   // ������ fighter
    "/daemon/skill/ghost/",     // ���޵ظ� ghost
    "/daemon/skill/gumu/",      // ��ԯ��Ĺ gumu
    "/daemon/skill/kusong/",    // ���ƶ� kusong
    "/daemon/skill/moon/",      // �¹� moon
    "/daemon/skill/pansi/",     // ��˿�� pansi
    "/daemon/skill/puti/",      // ����ɽ���Ƕ� puti
    "/daemon/skill/sanjie/",    // ����ɽ sanjie
    "/daemon/skill/shushan/",   // ��ɽ���� shushan 
    "/daemon/skill/wudidong/",  // �ݿ�ɽ�޵׶� wudidong
    "/daemon/skill/xueshan/",   // ��ѩɽ xueshan
    "/daemon/skill/zhenyuan/",  // ��ׯ�� zhenyuan
    "/daemon/skill/test/",      // �油���� test
});

mapping search = ([]);

void rehash(string path);

void create()
{
    int i;
    i = sizeof(path);
    set("no_clean_up",1);
    seteuid(geteuid());

    while (i--)
    {
        rehash(path[i]);
    }
}

void rehash(string dir)
{
    int i;
    string *cmds;

    if (dir[sizeof(dir) - 1] != '/')
        dir += "/";
    cmds = get_dir(dir);
    i = sizeof(cmds);
    while (i--)
        if (!sscanf(cmds[i], "%s.c", cmds[i]))
        {
            if (i == 0)
                cmds = cmds[1..sizeof(cmds)];
            else if (i == sizeof(cmds))
                cmds = cmds[0..<2];
            else
                cmds = cmds[0..i - 1] + cmds[i + 1..<1];
        }
    if (sizeof(cmds))
        search[dir] = cmds;
}

string find_skill(string skill)
{
    int i;

    i = sizeof(path);
    while (i--)
    {
        if (undefinedp(search[path[i]]))
            continue;
        if (member_array(skill, search[path[i]]) != -1)
            return path[i] + skill;
    }

    return 0;
}

